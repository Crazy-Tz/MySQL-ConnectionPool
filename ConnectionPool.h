#pragma once
#include<iostream>
#include<queue>
#include<mutex>
#include<atomic>
#include<thread>
#include<functional>
#include<condition_variable>
#include"Connection.h"
using std::mutex;
using std::atomic_int;
using std::queue;
using std::thread;
using std::bind;
using std::unique_lock;
using std::shared_ptr;
using std::cv_status;
using std::condition_variable;
//���ӳ���
class ConnectionPool
{
public:
	//��ȡ���ӳض���
	static ConnectionPool* getConnectionPool();
	//��ȡ�����е�����
	shared_ptr<Connection> getConnection();
private:
	ConnectionPool();
	//~ConnectionPool();
	//����������Ϣ
	bool loadConfigFile();
	//���������̺߳���
	void producerConnectionTask();
	//ɨ��������ࣨ����ʱ�䳬ʱ������
	void scannerConnectionTask();
	//�������ݿ���Ϣ
	string _ip;
	unsigned short _port;
	string _username;
	string _password;
	string _dbname;
	//���ӳػ�������
	int _initSize;
	int _maxSize;
	int _maxIdleTime;
	int _connectionTimeOut;
	//���ӳض���
	queue<Connection*> _connectionQue;
	//���ӳض����̰߳�ȫ������
	mutex _queueMutex;
	//���ӳ�������
	atomic_int _connectionCount;
	//�̼߳�ͬ��
	condition_variable _cv;
};