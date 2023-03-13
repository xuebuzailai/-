#pragma once
#include<iostream>
using namespace std;
#include"identity.h"
#include<fstream>
#include"globalfile.h"
#include<vector>
#include"student.h"
#include"teacher.h"
#include<algorithm>
#include"computerRoom.h"

class Manager :public Identity
{
public:
	//Ĭ�Ϲ���
	Manager();

	//�вι���
	Manager(string name, string pwd);


	//�˵�����
	void operMenu();

	//����˺�
	void addPerson();
	//�鿴�˺�
	void showPerson();
	//�鿴������Ϣ
	void showComputer();
	//���ԤԼϵͳ
	void cleanFile();

	//��ʼ������
	void initVector();

	//����ظ� ����һ ���ѧ��/ְ���� ������ �������
	bool checkRepeat(int id, int type);

	//ѧ������
	vector<Student>vStu;

	//��ʦ����

	vector<Teacher>vTea;

	//������Ϣ����
	vector<ComputerRoom>vCom;


};