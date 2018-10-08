def main():
    nozeroesCount = 0
    matrixmarket = []

    src = open(input('Source: '), 'r')
    dst = open(input('Destination: '), 'w')
    rows, cols = map(int, src.readline().split())

    for i in range(rows):
        row = list(map(float, src.readline().split()))

        for j in range(cols):
            if row[j] != 0:
                nozeroesCount += 1
                matrixmarket.append([i + 1, j + 1, row[j]])

    dst.write('{:d} {:d} {:d}\n'.format(rows, cols, nozeroesCount))
    for record in matrixmarket:
        dst.write('{:d} {:d} {:g}\n'.format(*record))

    src.close()
    dst.close()


if __name__ == '__main__':
    main()
