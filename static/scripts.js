document.addEventListener('DOMContentLoaded', function () {
    // Default table generation
    generateTable(3);

    document.getElementById('num_processes').addEventListener('change', function (event) {
        const selectedValue = parseInt(event.target.value, 10);
        generateTable(selectedValue);
    });

    document.querySelector('form').addEventListener('submit', function (event) {
        event.preventDefault();
        submitData();
    });
});

function generateTable(rows) {
    var tableContainer = document.getElementById('processTableContainer');
    tableContainer.innerHTML = ''; // Clear previous table

    var table = document.createElement('table');
    table.classList.add('table', 'table-bordered', 'table-striped');

    var thead = document.createElement('thead');
    var headerRow = document.createElement('tr');

    var headers = ['Process', 'Arrival Time', 'Burst Time', 'Priority'];
    headers.forEach(function (header) {
        var th = document.createElement('th');
        th.textContent = header;
        headerRow.appendChild(th);
    });

    thead.appendChild(headerRow);
    table.appendChild(thead);

    var tbody = document.createElement('tbody');
    for (var i = 1; i <= rows; i++) {
        var row = document.createElement('tr');

        var processCell = document.createElement('td');
        processCell.textContent = 'P' + i;
        row.appendChild(processCell);

        ['arrival_time', 'burst_time', 'priority'].forEach(function (type) {
            var cell = document.createElement('td');
            var input = document.createElement('input');
            input.type = 'number';
            input.name = type;
            input.value = '0'; // Set default value to zero
            input.classList.add('form-control');
            cell.appendChild(input);
            row.appendChild(cell);
        });

        tbody.appendChild(row);
    }

    table.appendChild(tbody);
    tableContainer.appendChild(table);
}

function submitData() {
    var algorithm = document.getElementById('algorithm').value;
    console.log('Algorithm:', algorithm); // Log algorithm value

    var rows = document.querySelectorAll('#processTableContainer table tbody tr');
    console.log('Number of rows:', rows.length); // Log number of rows

    var data = {
        algorithm: algorithm,
        processes: []
    };

    rows.forEach(function (row, index) {
        var cells = row.querySelectorAll('td input');
        var rowData = {
            process: 'P' + (index + 1),
            arrival_time: cells[0].value,
            burst_time: cells[1].value,
            priority: cells[2].value
        };
        data.processes.push(rowData);
    });

    console.log('Data:', data); // Log data array

    fetch('/submit', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json'
        },
        body: JSON.stringify(data)
    })
    .then(response => response.json())
    .then(data => {
        if (data.error) {
            console.error('Error from server:', data.error); // Debug print to console
            document.getElementById('div3').innerText = `Error: ${data.error}`;
        } else {
            console.log('Success from server:', data.output); // Debug print to console
            document.getElementById('div3').innerText = data.output;
        }
    })
    .catch(error => {
        console.error('Error in fetch:', error); // Debug print to console
        document.getElementById('div3').innerText = 'An error occurred while processing the request.';
    });
}
