import numpy as np
import matplotlib.pyplot as plt


def main():
    source_mysort = open('mysort_res.txt')
    source_qsort = open('qsort_res.txt')
    figure = plt.figure()
    figure.canvas.set_window_title('Sort time test')
    plt.title('mysort and qsort comparison');

    X_mysort = []
    Y_mysort = []
    for line in source_mysort.readlines():
        X_mysort.append(int(line.split()[0]))
        Y_mysort.append(float(line.split()[1]))
    X_mysort = np.array(X_mysort)
    Y_mysort = np.array(Y_mysort)

    X_qsort = []
    Y_qsort = []
    for line in source_qsort.readlines():
        X_qsort.append(int(line.split()[0]))
        Y_qsort.append(float(line.split()[1]))
    X_qsort = np.array(X_qsort)
    Y_qsort = np.array(Y_qsort)

    line_mysort, = plt.semilogy(X_mysort, Y_mysort, color='#4189f4')
    line_qsort, = plt.semilogy(X_qsort, Y_qsort, color='#f44242')

    plt.grid()
    plt.xlabel('Array elements amount');
    plt.ylabel('Number of tacts');
    plt.legend((line_mysort, line_qsort), ('mysort', 'qsort'), loc='best')
    plt.show()

    source_mysort.close()
    source_qsort.close()

if __name__ == '__main__':
    main()
