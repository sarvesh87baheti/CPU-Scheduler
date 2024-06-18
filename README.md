# CPU-Scheduler
## Project Details :
The project enables user to schedule processes, given their arrival times, burst times and priorities using five popular algorithms:
- First Come First Serve (FCFS)
- Shortest Job First (SJF)
- Shortest Remaining Time First (SRTF)
- Round Robin (RR)
- Priority Scheduling

The project displays scheduling of procceses, throughput, average waiting time and average turnaround time of the schedule.

## Setup and Installation :
1. Clone the github repository:
    Open your terminal and run the following command to clone the repository:
    git clone https://github.com/sarvesh87baheti/CPU-Scheduler.git

2. Navigate to the Project Directory:
    cd CPU-Scheduler

3. Create a Virtual Environment:

    It's recommended to use a virtual environment to manage dependencies. Run the following commands:

    ```bash
    python3 -m venv venv
    source venv/bin/activate  # On Windows use `venv\Scripts\activate`
    ```

4. **Install Dependencies**

    Install the necessary Python packages using `pip`:

    ```bash
    pip install -r requirements.txt
    ```

## Usage

### Running the Application

To start the application, run:

```bash
python scheduler.py
```

### Input Format

When prompted, enter the details of each process:

- **Arrival Time:** The time at which the process arrives in the ready queue.
- **Burst Time:** The total time required by the process for execution on the CPU.
- **Priority:** The priority of the process (for Priority Scheduling).

### Selecting Scheduling Algorithm

After entering the process details, choose the scheduling algorithm you want to use:

1. First Come First Serve (FCFS)
2. Shortest Job First (SJF)
3. Shortest Remaining Time First (SRTF)
4. Round Robin (RR)
5. Priority Scheduling

### Output

The application will display:
- Gantt chart of the scheduling
- Turnaround Time, Waiting Time, and Response Time for each process
- Average Turnaround Time, Average Waiting Time, and Average Response Time for the chosen algorithm

## Examples

### Example Input

```
Enter number of processes: 3
Process 1: Arrival Time: 0, Burst Time: 5, Priority: 2
Process 2: Arrival Time: 1, Burst Time: 3, Priority: 1
Process 3: Arrival Time: 2, Burst Time: 8, Priority: 3
Choose the scheduling algorithm (1-5): 1
```

### Example Output

```
Algorithm: First Come First Serve (FCFS)

Gantt Chart:
| P1 | P1 | P1 | P1 | P1 | P2 | P2 | P2 | P3 | P3 | P3 | P3 | P3 | P3 | P3 | P3 |

Turnaround Time: 
P1: 5, P2: 7, P3: 14

Waiting Time:
P1: 0, P2: 4, P3: 6

Response Time:
P1: 0, P2: 5, P3: 8

Average Turnaround Time: 8.67
Average Waiting Time: 3.33
Average Response Time: 4.33
```

## Contributing

Contributions are welcome! Please read the [CONTRIBUTING.md](CONTRIBUTING.md) for guidelines on how to contribute to the project.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- Inspired by operating systems and CPU scheduling concepts.
- Special thanks to the open-source community for continuous support.

---

Feel free to modify this README as per specific project needs or additional details.