// Test64ReadAllFile.cpp : 定义控制台应用程序的入口点。
#include <io.h>  
#include <fstream>  
#include <string>
#include <vector>
#include <iostream>
void GetAllFiles(std::string path, std::vector<std::string>& files)
{

	intptr_t   hFile = 0;
	//文件信息    
	struct _finddata_t fileinfo;//用来存储文件信息的结构体    
	std::string p;
	if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1)  //第一次查找  
	{
		do
		{
			if ((fileinfo.attrib &  _A_SUBDIR))  //如果查找到的是文件夹  
			{
				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)  //进入文件夹查找  
				{
					files.push_back(p.assign(path).append("\\").append(fileinfo.name));
					GetAllFiles(p.assign(path).append("\\").append(fileinfo.name), files);

				}
			}
			else //如果查找到的不是是文件夹   
			{
				//files.push_back(p.assign(fileinfo.name));  //将文件路径保存，也可以只保存文件名:    p.assign(path).append("\\").append(fileinfo.name)  

				files.push_back(p.assign(path).append("\\").append(fileinfo.name));
			}

		} while (_findnext(hFile, &fileinfo) == 0);

		_findclose(hFile); //结束查找  
	}

}
// 在路径中提取文件的名字
void GetName(std::vector<std::string> &vPath, std::vector<std::string> &vName)
{
	if (vPath.size() <= 0)
	{
		printf("vPath.size <= 0");
		return;
	}
	for (int i = 0; i < vPath.size(); i++)
	{
		std::string path = vPath[i];

		int pointDot = path.find_last_of('.');
		int pointN = path.find_last_of('\\');

		std::string name = path.substr(pointN + 1, pointDot - pointN - 1);

		vName.push_back(name);

	}

}

// 
int main()
{
	std::vector<std::string> mFileVec;

	std::string path = "C:\\Qt\\5.15.2\\msvc2019_64\\lib";
	GetAllFiles(path, mFileVec);
	for (int i = 0; i < mFileVec.size(); i++)
	{
		std::cout << mFileVec[i] << std::endl;
	}
	std::vector<std::string> vName;
	GetName(mFileVec, vName);
	for (int i = 0; i < mFileVec.size(); i++)
	{
		std::cout << vName[i] << std::endl;
	}
    return 0;
}