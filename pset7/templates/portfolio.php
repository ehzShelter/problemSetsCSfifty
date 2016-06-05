<ul class="nav nav-pills">
    <li><a href="quote.php">Quote</a></li>
    <li><a href="buy.php">Buy</a></li>
    <li><a href="sell.php">Sell</a></li>
    <li><a href="deposit.php">Deposit</a>
    <li><a href="history.php">History</a></li>
    <li><a href="reset.php"><i>Change Password</i></a></li>
    <li><a href="logout.php"><strong>Log Out</strong></a></li>
</ul>

<table class="table table-striped">
    <thead>
        <tr>
            <th>Symbol</th>
            <th>Name</th>
            <th>Shares</th>
            <th>Price</th>
            <th>Total</th>
        </tr>
    </thead>
    <tbody>
        <?php foreach ($positions as $row): ?>
          <tr>
              <td><?= $row["symbol"] ?></td>
              <td><?= $row["name"] ?></td>
              <td><?= $row["shares"] ?></td>
              <td>$<?= number_format($row["price"]) ?></td>
              <td>$<?= number_format($row["total"]) ?></td>
          </tr>
        <?php endforeach ?>
        <tr>
            <td colspan="4">CASH</td>
            <td> US $ <?= number_format($users, 2) ?> </td>
        </tr>
    </tbody>
</table>
