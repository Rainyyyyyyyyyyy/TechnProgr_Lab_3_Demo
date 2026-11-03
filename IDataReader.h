#ifndef IDATAREADER_H
#define IDATAREADER_H

#include <QString>
#include <QVector>
#include <QPointF>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

class IDataReader {
public:
    virtual ~IDataReader();
    virtual QVector<QPointF> getData() = 0;
};





class JsonDataReader{
private:
    QString filePath;       // путь к json-файлу

public:
    JsonDataReader(QString PathToFile = QString()) : filePath(PathToFile){ }
    ~JsonDataReader() = default;
    QVector<QPointF> getData(){
        if(filePath.isEmpty()){
            throw std::invalid_argument("Error: path to file is empty!");
        }

        QVector<QPointF> result;
        QFile file(filePath);
        if(!file.exists()){
            throw std::invalid_argument("Error: file does not exists!");
        }

        if(file.open(QFile::ReadOnly) == false){
            throw std::invalid_argument("Error: Unable to open file!");
        }


        QByteArray jsonData = file.readAll();
        file.close();

        QJsonParseError parseError;
        QJsonDocument doc = QJsonDocument::fromJson(jsonData, &parseError);

        if(parseError.error != QJsonParseError::NoError){
            throw std::invalid_argument("Error: Parsing file failed!");
        }

        // 5. Проверяем, что корень — это массив
        if (!doc.isArray()) {
            throw std::invalid_argument("Error: invalid file-format");
            // корневой элемент JSON должен быть массивом [...]

        }


        QJsonArray jsonArray = doc.array();
        for(const auto &i : jsonArray){
            QJsonObject current = i.toObject();
            double time = current["time"].toDouble();
            double value = current["value"].toDouble();

            result.append(QPointF(time, value));
        }

        return result;
    }


};

#endif // IDATAREADER_H
