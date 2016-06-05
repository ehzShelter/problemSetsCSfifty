<?php

    // configuration
    require("../includes/config.php");

    // retrive information from databases
    $rows =	query("SELECT symbol,shares FROM portfolios WHERE id = ?", $_SESSION["id"]);

    // positions array block
    $positions = [];

    foreach ($rows as $row)
    {
        // lookup stock
        $stock = lookup($row["symbol"]);

        if ($stock != false)
        {
            $positions[] = [
                "name" => $stock["name"],
                "price" => $stock["price"],
                "shares" => $row["shares"],
                "total" => $stock["price"] * $row["shares"],
                "symbol" => $row["symbol"]
            ];
        }
    }

    // retriving into template
    $users = query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);

    // render portfolio
    render("portfolio.php", ["title" => "Portfolio", "positions" => $positions,
        "users" => $users[0]["cash"]]);

?>
