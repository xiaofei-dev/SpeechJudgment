#include <iostream>
#include <string>
#include <vector>
#include<iostream>
#include <cstring>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>
#include<fstream>
#include "pitch/complex_defines.h"
#include "pitch/pitch.h"
//#include "pitch/pitch.cpp"
#include "pitch/resample.h"
//#include "pitch/resample.cpp"
#include "pitch/support_functions.h"
//#include "pitch/support_functions.cpp"

using std::vector;
using namespace std;
using namespace delta;

string vector2string(vector<float> vect);
void txtIO();
string split(const std::string& s, std::vector<float >& sv, const char* delim);
vector<vector<float>> process(const std::vector<float>& data);

int main() {
    txtIO();
    cout << "hello world" << endl;
    return 0;
}

string split(const std::string& s,
             std::vector<float >& sv,
             const char* delim) {
//    string res = s.substr(0, s.find('=', 0));
//    string data = s.substr(s.find('[', 0) + 1, s.length() - 1);
    string res = s.substr(0, s.find(',', 0));
    string data = s.substr(s.find(',', 0) + 1, s.length());
    sv.clear();                                 // 1.
    char* buffer = new char[data.size() + 1];      // 2.
    buffer[data.size()] = '\0';
    std::copy(data.begin(), data.end(), buffer);      // 3.
    char* p = std::strtok(buffer, delim);       // 4.
    do {
        sv.push_back(std::stof(p));                        // 5.
    } while ((p = std::strtok(NULL, delim)));   // 6.
    delete[] buffer;
    return res;
}

string vector2string(vector<float> vect){
    std::stringstream ss;
    ss << "[";
    for(size_t i = 0; i < vect.size(); ++i)
    {
        if(i != 0)
            ss << ", ";
        ss << vect[i];
    }
    ss << "]";
    std::string s = ss.str();
    return s;
}

string dimen_vector2string(vector<vector<float>> vect){
    std::stringstream ss;
    for(size_t i = 0; i < vect.size(); ++i){
        if(i != 0)
            ss << ", ";
        ss << vector2string(vect[i]);
    }

    std::string s = ss.str();
    return s;
}

//过滤概率
//float prob_limit = 0.5f;
string dimen_vector2string_filterPitch(vector<vector<float>> vect){
    std::stringstream ss;
    for(size_t i = 0; i < vect.size(); ++i){
        if(i != 0){
            ss << ", ";
        }

        /*vector<float> v = vect[i];
        if(v[0] < prob_limit){
            ss << 0;
        } else {
            ss << v[1];
        }*/
        ss << vect[i][1];
    }
    std::string s = ss.str();
    return s;
}

string dimen_vector2string_filterNCCF(vector<vector<float>> vect){
    std::stringstream ss;
    for(size_t i = 0; i < vect.size(); ++i){
        if(i != 0){
            ss << ", ";
        }

        /*vector<float> v = vect[i];
        if(v[0] < prob_limit){
            ss << 0;
        } else {
            ss << v[1];
        }*/
        ss << vect[i][0];
    }
    std::string s = ss.str();
    return s;
}

int number = 0;
vector<vector<float>> process(const std::vector<float>& data){
    vector<vector<float>> res = vector<vector<float>>();
    delta::PitchExtractionOptions options = delta::PitchExtractionOptions();
    delta::ComputeKaldiPitch(options, data, &res);
    int size = data.size();
    int sizeRes = res.size();
    number++;
    string info = to_string(number) + " file " + "end";
    cout << info << endl;
    return res;
}


void txtIO(){
    string s;
    //以二进制模式打开 in.txt 文件
    ifstream inFile("D:\\CPP\\SpeechJudgment\\input12_1.txt", ios::in | ios::binary);

    ofstream outFilePitch("D:\\CPP\\SpeechJudgment\\output12_1_Pitch.txt", ios::out | ios::trunc); //利用构造函数创建txt文本，并且打开该文本
    ofstream outFileNCCF("D:\\CPP\\SpeechJudgment\\output12_1_NCCF.txt", ios::out | ios::trunc); //利用构造函数创建txt文本，并且打开该文本
    //判断文件是否正常打开
    if (!inFile) {
        cout << "file error" << endl;
    }

    std::vector<float> vect = std::vector<float>();

    //从输入文件中读取一行字符串
//    int i = 0;
    while (getline(inFile, s)){
//        if (i == 5) break;
        string res = split(s, vect, ",");
        outFilePitch << res << ",";
        outFileNCCF << res << ",";
        vector<vector<float>> dimen_vect = process(vect);
        outFilePitch << dimen_vector2string_filterPitch(dimen_vect) << endl;
        outFileNCCF << dimen_vector2string_filterNCCF(dimen_vect) << endl;

//        i++;
//        outFile << dimen_vector2string(dimen_vect) << endl;
//        cout << s << endl;
    }
    inFile.close();
    outFilePitch.close();
    outFileNCCF.close();
}