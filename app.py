from flask import Flask, render_template, request, jsonify
import subprocess
import os

from flask_cors import CORS

app = Flask(__name__)
CORS(app)  # Enable CORS for all routes

@app.route('/')
def hello_world():
    return render_template('index.html')

@app.route('/submit', methods=['POST'])
def submit():
    print("Received a POST request")  # Log statement
    try:
        data = request.get_json()
        print("Received data:", data)  # Debug print to console
    except Exception as e:
        print("Error parsing JSON:", e)  # Log error
        return jsonify({'error': 'Invalid JSON format'}), 400

    algorithm = data.get('algorithm')
    processes = data.get('processes')

    if not algorithm or not processes:
        return jsonify({'error': 'Missing data'}), 400

    # Prepare input for the C++ program
    input_data = f"{len(processes)}\n"
    input_data += ' '.join([str(p['arrival_time']) for p in processes]) + '\n'
    input_data += ' '.join([str(p['burst_time']) for p in processes]) + '\n'
    input_data += ' '.join([str(p['priority']) for p in processes]) + '\n'

    print("Input data for FCFS C++ program:")
    print(input_data)  # Debug print to console

    if algorithm == 'FCFS':

        # Construct the absolute path to the executable
        executable_path = os.path.join(os.getcwd(), 'fcfs.exe')

        # Run the C++ program
        process = subprocess.Popen([executable_path], stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        stdout, stderr = process.communicate(input_data.encode())

        if stderr:
            print("Error from C++ program:", stderr.decode())  # Debug print to console
            return jsonify({'error': stderr.decode()}), 500

        output = stdout.decode()
        print("Output from C++ program:", output)  # Debug print to console
        return jsonify({'output': output})

    if algorithm == 'Round Robin':

        # Construct the absolute path to the executable
        executable_path = os.path.join(os.getcwd(), 'roundRobin.exe')

        # Run the C++ program
        process = subprocess.Popen([executable_path], stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        stdout, stderr = process.communicate(input_data.encode())

        if stderr:
            print("Error from C++ program:", stderr.decode())  # Debug print to console
            return jsonify({'error': stderr.decode()}), 500

        output = stdout.decode()
        print("Output from C++ program:", output)  # Debug print to console
        return jsonify({'output': output})
    
    if algorithm == 'SJF':

        # Construct the absolute path to the executable
        executable_path = os.path.join(os.getcwd(), 'sjf.exe')

        # Run the C++ program
        process = subprocess.Popen([executable_path], stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        stdout, stderr = process.communicate(input_data.encode())

        if stderr:
            print("Error from C++ program:", stderr.decode())  # Debug print to console
            return jsonify({'error': stderr.decode()}), 500

        output = stdout.decode()
        print("Output from C++ program:", output)  # Debug print to console
        return jsonify({'output': output})
    
    if algorithm == 'SRTF':

        # Construct the absolute path to the executable
        executable_path = os.path.join(os.getcwd(), 'srtf.exe')

        # Run the C++ program
        process = subprocess.Popen([executable_path], stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        stdout, stderr = process.communicate(input_data.encode())

        if stderr:
            print("Error from C++ program:", stderr.decode())  # Debug print to console
            return jsonify({'error': stderr.decode()}), 500

        output = stdout.decode()
        print("Output from C++ program:", output)  # Debug print to console
        return jsonify({'output': output})
    
    if algorithm == 'Priority Scheduling':

        # Construct the absolute path to the executable
        executable_path = os.path.join(os.getcwd(), 'priority.exe')

        # Run the C++ program
        process = subprocess.Popen([executable_path], stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        stdout, stderr = process.communicate(input_data.encode())

        if stderr:
            print("Error from C++ program:", stderr.decode())  # Debug print to console
            return jsonify({'error': stderr.decode()}), 500

        output = stdout.decode()
        print("Output from C++ program:", output)  # Debug print to console
        return jsonify({'output': output})
    print("Unsupported algorithm:", algorithm)  # Debug print to console
    return jsonify({'error': 'Unsupported algorithm'}), 400

if __name__ == "__main__":
    app.run(debug=True)
