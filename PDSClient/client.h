#ifndef CLIENT_H
#define CLIENT_H
#include <QtNetwork>
#include <symbol.h>
#include <iostream>
#include <message.h>
#include "fileinfo.h"

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject* parent = 0);
    ~Client();
    void login(QString username, QString password);
    void registration(QString username, QString password, QString nick);
    void getFiles();
    void getFile(int fileIndex);
    void closeFile(int fileIndex);
    int getSiteId();
    QTcpSocket* getSocket();
    void requestURI(int fileIndex);
    void getFileFromURI(QString uri);
    void addFile(FileInfo * file);
    void eraseFile(int fileIndex);
    QString getUsername();
    QString getNickname();
    QVector<FileInfo *> getMyFileList();
    void setFileIndex(int index);

signals:
    void login_successful();
    void login_failed();
    void registration_successful();
    void registration_failed(int status);
    void message_from_server(Message m);
    void files_list_refreshed(QVector<FileInfo *> files);
    void file_ready(QVector<Symbol *> s);
    void URI_Ready(QString uri);
    void disconnect_URI();
    void signal_connection(int siteId, QString nickname, int ins);
    void signal_owners(QMap<int, QString> owners);
    void remote_cursor_changed(int index, int siteIdSender);
    void uri_error();
    void file_erased(int index);
    void erase_file_error();

public slots:
    void onMessageReady(QVector<Message> messages, int fileIndex);
    void onMyCursorPositionChanged(int index);
    void disconnectFromServer();

private slots:
    void onConnected();
    void onReadyRead();

private:
    QTcpSocket* socket;
    QString username;
    QString nickname;
    QString password;
    int siteId;
    int counter;
    int fileIndexOpened;
    QVector<FileInfo *> files;
    QVector<Symbol*> symbols;
    QMap<int, QString> connectedUsers; //non usata per ora

};

#endif // CLIENT_H
