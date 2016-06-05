<?php

require("../includes/config.php");

if ($_SERVER["REQUEST_METHOD"] == "GET")
{
    $portfolios = query ("SELECT symbol FROM portfolios where id = ?", $_SESSION["id"]);

    $temp = [];

    foreach ($portfolios as $row)
    {
        $temp[] = $row["symbol"];
    }
    render("sell_form.php", ["title" => "Sell", "portfolios" => $temp]);
}

else
{
    if (empty($_POST["symbol"]))
    {
        apologize("You must give a stock symbol");
    }

    else
    {
        $shares = query ("SELECT shares from portfolios WHERE id = ? AND symbol = ?",
            $_SESSION["id"] ,$_POST["symbol"]);

        $stock = lookup($_POST["symbol"]);

        $totalPrice = $stock["price"] * $shares[0]["shares"];

        query ("UPDATE users SET cash = cash + ? WHERE id = ?",
            $totalPrice, $_SESSION["id"]);

        query ("DELETE FROM portfolios WHERE id = ? AND symbol = ?",
            $_SESSION["id"], $_POST["symbol"]);


        $transaction = "SELL";

        query("INSERT INTO history (transaction, timespan, symbol,
            shares, price, id) VALUES(?, NOW(), ?, ?, ?, ?)",
            $transaction, strtoupper($stock["symbol"]), $shares[0]["shares"],
            $stock["price"], $_SESSION["id"]);

            // redirecting to portfolio
            redirect("/");
    }
}
