import matplotlib.pyplot as plt


def main():
    source = open('out.txt')
    figure = plt.figure()
    figure.canvas.set_window_title('temperature difference')
    plt.title('temperature difference');

    X = []
    Y = []
    for line in source.readlines():
        X.append(int(line.split()[0]))
        Y.append(float(line.split()[1]))

    source.close()

    line_qsort, = plt.plot(X, Y)

    plt.grid()
    plt.xlabel('years');
    plt.ylabel('temperature difference');
    plt.show()


if __name__ == '__main__':
    main()
