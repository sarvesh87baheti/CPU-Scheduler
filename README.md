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
    ```cmd
    git clone https://github.com/sarvesh87baheti/CPU-Scheduler.git
    ```

2. Navigate to the Project Directory
    ```bash
    cd CPU-Scheduler
    ```

3. Create a Virtual Environment
    It is recommended to use a virtual environment to manage dependencies. Run the following commands:
    ```bash
    python3 -m venv venv
    source venv/bin/activate  # On Windows use `venv\Scripts\activate`
    ```

4. Install Dependencies
    Install the necessary Python packages using:
    ```bash
    pip install -r requirements.txt
    ```

## Usage
### Running the Application
1.  To start the application, run:
    ```bash
    python app.py
    ```

2. The will start running on http://127.0.0.1:5000. Navigate to that address on any web browser

3.  Enter the process details and choose the scheduling algorithm you want to use

4.  Press submit

### Output
The application will display:
- Scheduling of each process
- Average Turnaround Time, Average Waiting Time, and Throughput for the chosen algorithm

### Internal Working
- Internally, the scheduling is done using C++ programs
- The application takes input using GUI developed, which is converted to the input format required by the cpp executable programs
- The input data is sent to the server using Flask
- The program corresponding to desired algorithm is run, and output is printed in results section 
- The program also calculates waiting time, throughput, etc and displays it

### References
- https://www.geeksforgeeks.org/cpu-scheduling-in-operating-systems/