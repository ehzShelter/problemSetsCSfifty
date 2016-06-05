<?php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // render form
        render("reset_form.php", ["title" => "Reset"]);
    }
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        if (empty($_POST["username"]))
        {
            apologize('username field is not set');
        }
        else
        {
            // query database for user
            $rows = query("SELECT * FROM users WHERE username = ?", $_POST["username"]);

            // if we found user, check password
            if (count($rows) == 1)
            {
                $row = $rows[0];

                if (empty($_POST["curr_password"]))
                {
                    apologize('you must provide your stored password');
                }
                else if (crypt($_POST["curr_password"], $row["hash"]) != $row["hash"])
                {
                    apologize("Password don't match with currently stored password");
                }
                else if (empty($_POST["new_password"]) && empty($_POST["confirmation"]))
                {
                    apologize('you must provide a new password with confirmation');
                }
                else if ($_POST["new_password"] != $_POST["confirmation"])
                {
                    apologize('new password confirmation failed ! ');
                }
                else
                {
                    $reset = query("UPDATE users SET hash = ?", crypt($_POST["new_password"]));

                    if ($_POST["new_password"] == $_POST["curr_password"])
                    {
                        apologize("Bro...MAD!! you want to change your password\n,
                            your current pass and new pass are same");
                    }
                    else if ( $reset === false )
                    {
                        apologize("Can't update password");
                    }
                    else
                    {
                        $_SESSION["id"] = $row["id"];
                        redirect("index.php");
                    }
                }
            }
            else
            {
                apologize("Username is Invalid");
            }
        }

    }
    else
    {
        apologize("something went wrong");
    }
?>
