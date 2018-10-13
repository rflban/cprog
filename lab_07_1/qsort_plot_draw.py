import numpy as np
import matplotlib.pyplot as plt


def main():
    source_qsort = open('qsort_time_res.txt')
    figure = plt.figure()
    figure.canvas.set_window_title('qsort time test')
    plt.title('qsort');

    X_qsort = []
    Y_qsort = []
    for line in source_qsort.readlines():
        X_qsort.append(int(line.split()[0]))
        Y_qsort.append(float(line.split()[1]))
    X_qsort = np.array(X_qsort)
    Y_qsort = np.array(Y_qsort)

    line_qsort, = plt.plot(X_qsort, Y_qsort, color='#f44242')

    plt.grid()
    plt.xlabel('Array elements amount');
    plt.ylabel('Number of tacts');
    plt.legend((line_qsort,), ('qsort',), loc='best')
    plt.show()

    source_qsort.close()

if __name__ == '__main__':
    main()
