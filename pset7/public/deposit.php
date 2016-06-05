<?php

// autoloading
require("../includes/config.php");

if ($_SERVER["REQUEST_METHOD"] == "POST")
{
    if (empty($_POST["fund"]))
    {
        apologize("you must enter an amount to deposit");
    }

    if (preg_match("/^(\d*)?(\.\d+)?$/", $_POST["fund"]) == false)
    {
        apologize("Invalid amount");
    }
    else
    {
        query("UPDATE users SET cash = cash + ? WHERE id = ?",
            $_POST["fund"], $_SESSION["id"]);
    }

    redirect("/");
}
else
{
    render("deposit_form.php", ["title" => "Deposit"]);
}

?>
