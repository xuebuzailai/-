#include"orderFile.h"

//构造函数
OrderFile::OrderFile()
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);
	string date;//日期
	string interval;//时间段
	string stuId;//学生编号
	string stuName;//学生姓名
	string roomId;//机房编号
	string status;//预约状态

	this->m_Size = 0;//记录预约条数
	while (ifs >> date && ifs >> interval && ifs >> stuId && ifs >> stuName && ifs >> roomId && ifs >> status)
	{
		
		map<string, string>m;

		getMap(date, m);
		getMap(interval, m);
		getMap(stuId, m);
		getMap(stuName, m);
		getMap(roomId, m);
		getMap(status, m);

	
		this->m_OrderData.insert(make_pair(this->m_Size, m));
		this->m_Size++;
	}
	ifs.close();

}
void OrderFile::getMap(string& word, map<string, string>& m)
{
	string key;
	string value;


	int pos = word.find(":");//返回4
	if (pos != -1)
	{
		key = word.substr(0, pos);
		value = word.substr(pos + 1, word.size() - pos - 1);

		m.insert(make_pair(key, value));
	}
}

//更新预约记录
void OrderFile::updateOrder()
{
	if (this->m_Size == 0)
	{
		return;//预约记录零条，直接return
	}
	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
	for (int i = 0; i < this->m_Size; i++)
	{
		ofs << "date:" << this->m_OrderData[i]["date"] << " ";
		ofs << "interval:" << this->m_OrderData[i]["interval"] << " ";
		ofs << "stuId:" << this->m_OrderData[i]["stuId"] << " ";
		ofs << "stuName:" << this->m_OrderData[i]["stuName"] << " ";
		ofs << "roomId:" << this->m_OrderData[i]["roomId"] << " ";
		ofs << "status:" << this->m_OrderData[i]["status"] << endl;
	}
	ofs.close();

}

void OrderFile::showAllOrder()
{
	if (this->m_Size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < this->m_Size; i++)
	{
		cout << i + 1 << "、 ";
		cout << "预约日期：周" << this->m_OrderData[i]["date"];
		cout << " 时间段：" << (this->m_OrderData[i]["interval"] == "1" ? "上午" : "下午");
		cout << " 学号：" << this->m_OrderData[i]["stuId"];
		cout << " 姓名：" << this->m_OrderData[i]["stuName"];
		cout << " 机房编号：" << this->m_OrderData[i]["roomId"];
		string status = "状态：";
		//1、审核中 2、已预约 -1、预约失败 0、取消预约
		if (this->m_OrderData[i]["status"] == "1")
		{
			status += "审核中";
		}
		else if (this->m_OrderData[i]["status"] == "2")
		{
			status += "预约成功";
		}
		else if (this->m_OrderData[i]["status"] == "-1")
		{
			status += "预约失败，审核未通过";
		}
		else if (this->m_OrderData[i]["status"] == "0")
		{
			status += "预约已经取消";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
}
