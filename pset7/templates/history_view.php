<table class="table table-striped">
    <thead>
        <tr>
            <th>Transaction</th>
            <th>Date/Time</th>
            <th>Symbol</th>
            <th>Shares</th>
            <th>Price</th>
        </tr>
    </thead>

    <tbody>
    <?php foreach ($history as $position): ?>
        <tr>
            <td> <?= $position["transaction"] ?> </td>
            <td> <?= $position["timespan"] ?> </td>
            <td> <?= $position["symbol"] ?> </td>
            <td> <?= $position["shares"] ?> </td>
            <td> <?= number_format($position["price"], 2) ?> </td>
        </tr>
    <?php endforeach ?>
    </tbody>
</table>
