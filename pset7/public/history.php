<?php

require("../includes/config.php");

$history = query("SELECT * FROM history WHERE id = ?", $_SESSION["id"]);
render("history_view.php", ["title" => "History", "history" => $history]);

?>
