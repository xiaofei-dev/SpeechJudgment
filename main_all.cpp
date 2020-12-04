//#include <iostream>
//#include <string>
//#include <vector>
//#include<iostream>
//#include <cstring>
//#include <algorithm>
//#include <stdlib.h>
//#include <stdio.h>
//#include <sstream>
//#include<fstream>
//#include "./pitch.h"
//#include "./support_functions.h"
//#include "./pitch.cpp"
//#include "./complex_defines.h"
//#include "./resample.cpp"
//#include "./resample.h"
//#include "./support_functions.cpp"
//using std::vector;
//using namespace std;
//using namespace delta;
//
//string vector2string(vector<float> vect);
//void txtIO();
//string split(const std::string& s, std::vector<float >& sv, const char* delim);
//vector<vector<float>> process(const std::vector<float>& data, string name);
//
//int main() {
//    txtIO();
//    cout << "hello world" << endl;
//    return 0;
//}
//
//string split(const std::string& s,
//             std::vector<float >& sv,
//             const char* delim) {
//    string res = s.substr(0, s.find(',', 0));
//    string data = s.substr(s.find(',', 0) + 1, s.length());
//    sv.clear();                                 // 1.
//    char* buffer = new char[data.size() + 1];      // 2.
//    buffer[data.size()] = '\0';
//    std::copy(data.begin(), data.end(), buffer);      // 3.
//    char* p = std::strtok(buffer, delim);       // 4.
//    do {
//        sv.push_back(std::stof(p));                        // 5.
//    } while ((p = std::strtok(NULL, delim)));   // 6.
//    delete[] buffer;
//    return res;
//}
//
//string vector2string(vector<float> vect){
//    std::stringstream ss;
//    ss << "[";
//    for(size_t i = 0; i < vect.size(); ++i)
//    {
//        if(i != 0)
//            ss << ", ";
//        ss << vect[i];
//    }
//    ss << "]";
//    std::string s = ss.str();
//    return s;
//}
//
//string dimen_vector2string(vector<vector<float>> vect){
//    std::stringstream ss;
//    for(vector<float> v : vect){
//        ss << "[";
//        for(size_t i = 0; i < v.size(); ++i)
//        {
//            if(i != 0)
//                ss << ", ";
//            ss << v[i];
//        }
//        ss << "],";
//    }
//
//    std::string s = ss.str();
//    return s;
//}
//
////过滤概率
//float prob_limit = 0.5f;
//string dimen_vector2string_filter(vector<vector<float>> vect){
//    std::stringstream ss;
//    for(size_t i = 0; i < vect.size(); ++i){
//        if(i != 0){
//            ss << ", ";
//        }
//        ss << vect[i][1];
//    }
//    std::string s = ss.str();
//    return s;
//}
//
//vector<vector<float>> process(const std::vector<float>& data, string name){
//    vector<vector<float>> res = vector<vector<float>>();
//    delta::PitchExtractionOptions options = delta::PitchExtractionOptions();
//    delta::ComputeKaldiPitch(options, data, &res);
//    int size = data.size();
//    int sizeRes = res.size();
//    cout << "end" << endl;
//    return res;
//}
//
//
//void txtIO(){
//    string s;
//    //以二进制模式打开 in.txt 文件
//    //input format: filename,data_one,data_tow,data_three,.....data_n; one file one line;deliter is ","
//    //output format: filename,pitch_one,pitch_two,pitch_three,.....pitch_n;one file one line ;deliter is ","
//    ifstream inFile("/root/xinyuan/wav_txt/2st_wav_txt.txt", ios::in | ios::binary);
//
//    ofstream outFile("/root/xinyuan/wav_txt/2st_pitch.txt", ios::out | ios::trunc); //利用构造函数创建txt文本，并且打开该文本
//    //判断文件是否正常打开
//    if (!inFile) {
//        cout << "file error" << endl;
//    }
//
//    std::vector<float> vect = std::vector<float>();
//
//    //从输入文件中读取一行字符串
//    while (getline(inFile, s)){
//        string res = split(s, vect, ",");
//        outFile << res << ",";
//        outFile << dimen_vector2string_filter(process(vect, res)) << endl;
//    }
//    inFile.close();
//    outFile.close();
//}
