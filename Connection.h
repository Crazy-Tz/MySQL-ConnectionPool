#pragma once
#include<iostream>
#include<string>
#include<ctime>
#include<mysql.h>
using std::cout;
using std::endl;
using std::string;
#include"public.h"

// ���ݿ������
class Connection
{
public:
	// ��ʼ�����ݿ�����
	Connection();
	// �ͷ����ݿ�������Դ
	~Connection();
	// �������ݿ�
	bool connect(string ip, unsigned short port, string user, string password,
		string dbname);
	// ���²��� insert��delete��update
	bool update(string sql);
	// ��ѯ���� select
	MYSQL_RES* query(string sql);
	void refreshAliveTime() { _connectionAliveTime = clock(); }
	int getConnectionAliveTime() { return clock() - _connectionAliveTime; }
private:
	MYSQL* _conn; // ��ʾ��MySQL Server��һ������
	clock_t _connectionAliveTime;//��¼���ӵ�����ʱ��
};