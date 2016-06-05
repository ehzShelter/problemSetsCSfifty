<?php

require("../includes/config.php");

if ($_SERVER["REQUEST_METHOD"] == "GET")
{
    render("buy_form.php", ["title" => "Buy"]);
}

else
{
    if (empty($_POST["symbol"]) || empty($_POST["shares"]))
    {
        apologize("Stock Symbol or share is empty or both");
    }

    if ((!is_numeric($_POST["shares"]) || (preg_match("/^\d+$/", $_POST["shares"]) == false)))
    {
       apologize("shares must be a positive integer");
    }

    $stock = lookup($_POST["symbol"]);

    if ($stock === false)
    {
        apologize("Invalid Symbol");
    }
    else
    {
        $currentCost = $stock["price"] * $_POST["shares"];
        $row = query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);

        if ($row[0]["cash"] < $currentCost)
        {
            apologize("you can't afford the money");
        }
        else
        {
            // add stocks and update shares avoiding duplicate
            query("INSERT INTO portfolios (id, symbol, shares) VALUES(?, ?, ?)
                ON DUPLICATE KEY UPDATE shares = shares + VALUES(shares)",
                $_SESSION["id"], strtoupper($stock["symbol"]), $_POST["shares"]);

            // update cash
            query("UPDATE users SET cash = cash - ? WHERE id = ?",
            $currentCost, $_SESSION["id"]);

            $transaction = "BUY";

            query("INSERT INTO history (transaction, timespan, symbol,
                shares, price, id) VALUES(?, NOW(), ?, ?, ?, ?)",
                $transaction, strtoupper($stock["symbol"]), $_POST["shares"],
                $stock["price"], $_SESSION["id"]);

            // redirecting to portfolio
            redirect("/");

        }
    }
}

?>
