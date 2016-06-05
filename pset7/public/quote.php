<?php

// configuration
require("../includes/config.php");

// assuming the quote form was submitted and
// requset have reached through POST(routing)
if ($_SERVER['REQUEST_METHOD'] == 'POST')
{
    if (empty($_POST['symbol']))
    {
        apologize("you have not submitted the form correctly or something else");
    }
    else
    {
        // lookup for stock through yahoo finance
        $stock = lookup($_POST['symbol']);

        // make sure for undefined behaviour
        // if for some reason lookup send false, APOLOGIZE
        if ($stock == false)
        {
            apologize("Invalid stock symbol has been submitted");
        }
        else
        {
            // render the quote_retrive template
            render("quote_retrive.php", ["title" => "Quote",
                "symbol" => $stock["symbol"],
                "name" => $stock["name"],
                "price" => $stock["price"]
                ]
            );
        }

    }
}
else
{
    // else render aka redirect to quote_form page
    render("quote_form.php", ["title" => "Quota"]);
}

?>
