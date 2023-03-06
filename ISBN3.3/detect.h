/**
 * @author FoPluto
*/
#ifndef DETECT
#define DETECT

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>


using namespace std;
using namespace cv;

#define ERROR -1
#define DONE 0

// �궨�壺�����ע�;��Ǵ򿪶�ӦDEBUGģʽ

// #define DEBUG_ALL

#ifdef DEBUG_ALL

//#define DEBUG

#define DEBUG_THRESHOLD // ��ֵ������
#define DEBUG_RES // Ԥ��������

#endif

typedef pair<int, pair<int, int>> PIII;

typedef pair<int, int> PII;



class detectSolution {
private:
    // ����ͼƬ��·��
    string sampleImgPath;

    Mat src_image;          // ����ͼƬ
    Mat src_copy_image;     // ��������ͼƬ
    Mat gray_image;
    Mat threshold_image;    // ����֮��Ķ�ֵ��ͼƬ
    Mat rotated_image;      // ��ת֮���ͼ��
    Mat res_image;          // ������ɵ�ͼ����ȡ��Ȥ��ʱ��
    Mat ROI_image;          // ��ȡ��Ȥ��

    vector<int> rows_element;   // ��ROI����Ȥ����
    vector<Point> points;       // ���ڱ�ʾ��ÿһ�е�����ֵ����100���ص������
    vector<PIII> ans;           // �洢�𰸵�����
    vector<int> num_area;       // ���ֵ�ROI����Ȥ���򣬼��ַ��ָ�
    vector<PII> num_position;   // ���ֵ�λ����Ϣ�������ַ��ָ�
    vector<Mat> num_ROI_rect;   // ���ֵ�Mat����ȡ���ֵĽ��

    std::string res_str;  // ���յĴ�

    double ChNum;       // �ַ�׼ȷ��

    double StrNum;      // �ַ���׼ȷ��

    double average;

private:

    // ��ת����
    void ImgRectify(Mat& pic, Mat& BinaryFlat);

    // ��ȡƽ������
    void get_average_light(Mat _src);

    // ����ͼ�����ص�ֵ��ƽ��ֵ�����ڷ���
    double CalcImg(Mat inputImg);

    // ģ��ƥ�����Ҫ����
    char CheckImg(Mat inputImg, int idx);

    // ˮ������
    void FloodFill(Mat& pic);

    // Ԥ��������, ����ֵ��ֵ��res_image
    Mat get_res_image(Mat& src_image, int type);

    // resize_stand��������ͼƬresize��Ϊ��С�ߴ磬���ټ�����
    void resize_stand();

    // find_ROI����������Ѱ�Ҹ���Ȥ����
    void find_ROI();

public:

    // ���캯��
    detectSolution(string sample_path) { this->sampleImgPath = sample_path; }

    // ��ȡ���
    string get_res();

    // ��ȡ�ַ�׼ȷ��
    double getChNum();

    // ��ȡ�ַ���׼ȷ��
    double getStrNum();

    // fit��������������ʶ��Ľӿ�
    int fit(string src_path);

};

#endif