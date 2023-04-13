from flask import Flask, render_template, request
import subprocess

app = Flask(__name__)

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/execute', methods=['POST'])
def execute():
    buyer = request.form['buyer']
    seller = request.form['seller']
    No_of_stocks = request.form['No_of_stocks']
    trading_price = request.form['trading_price']

    # command = ['g++', '-o', 'bse', 'bse.cpp']
    # subprocess.run(command)

    command = ['./main', buyer, seller, No_of_stocks, trading_price]
    result = subprocess.run(command, capture_output=True)

    if result.returncode == 0:
        return render_template('result.html', output=result.stdout.decode('utf-8'))
    else:
        return render_template('error.html', error=result.stderr.decode('utf-8'))

if __name__ == '__main__':
    app.run(debug=True)
