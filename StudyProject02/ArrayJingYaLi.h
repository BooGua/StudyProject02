#pragma once
#include<vector>
#include"ArgClass.h"

/*
��������ģ�⾮Ͳ��������ֱ��Ͳ���ֺ�ˮƽ��Ͳ���֡�
���ฺ������ܾ�Һ��ѹ������Ħ���������Լ�����Ħ�衣
*/

using namespace std;

class ArrayJingYaLi {
private:
	double HEIGHT_UPRIGHT = 100; //��Ͳ��ֱ�߶�
	double LENGTH_HORIZONTAL = 200; //��Ͳˮƽ����
	double moment_height = 0; //Һ����ʱ��ֱ�߶�
	double moment_length = 0; //Һ����ʱˮƽ����

	/*
	�������Ħ��������ʱ��
	*/
	double array_holeLength = 0;
	double array_holeDensity = 0;
	double array_emissvity = 0;
	double array_density = 0; //ѹ��Һ�ܶ�,����kind��ͬ�ı�

	double M_sand = 0; //ͨ�����۵�֧�ż�����,�ۻ�����Kg��Mmax=907Kg	
	double Q = 0; //�ų��ε�����

	double JingYeZhu = 0;
	double MoCaZuLi = 0;
	double KongYanMoZu = 0;
	double PressureJ = 0;
	double ResistanceBend = 0;

	vector<ArgClass> arrayList_height; //��ֱ����
	vector<ArgClass> arrayList_horizontal; //ˮƽ����

public:
	/*
	��ֱ��Ͳ����һ��Һ��
	*/
	void attach(ArgClass argArrayClass);
	/*
	ˮƽ��Ͳ����һ��Һ��
	*/
	void attach_horizontal(ArgClass argArrayClass);
	/*
	�����ܾ�Һ��ѹ��
	*/
	double CalculateJingYeZhuYaLi();
	/*
	������Ħ������
	*/
	double CalculateMoCaZuLi();
	/*
	�������Ħ��
	*/
	double CalculateKongYanMoZu();
	/*
	�����ܾ�ѹ��
	*/
	double CalculateJingYaLi();
};