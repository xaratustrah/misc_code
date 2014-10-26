#ifndef CSVWRITER_H
#define CSVWRITER_H

#include <QObject>

class CsvWriter : public QObject
{
Q_OBJECT
public:
    explicit CsvWriter(QObject *parent = 0);

signals:

public slots:
    void saveCsvFile();
    void openCsvFile();
};

#endif // CSVWRITER_H
