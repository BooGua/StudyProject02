#pragma once
/*
�������ڴ洢�ɱ������ͬʱ����˱����µľ�Ͳ��Һ��ѹ������ͲĦ����������ѹ��,ģ��ÿһ��Һ�塣
*/
class ArgClass {
public:
	ArgClass();
	ArgClass(double pressureJ, double q, double sandMass, double dVolume, int kind, double dVorD,
		double dTorT, double resistanceBend, double speedFlow, double slope,
		double sandRatio, double dragReduction, double holeLength, double holeDensity, double emissvity);
	//15��������
	ArgClass(ArgClass argArrayClass, double height);
	void Calculator();
	~ArgClass();

	double getPressureJ();
	double getQ();
	double getSandMass();
	double getdVolume();
	int	   getKind();
	double getdVorD();
	double getdTorT();
	double getResistanceBend();
	double getSpeedFlow();
	double getSlope();
	double getSandRatio();
	double getDragReduction();

	double getHoleLength();
	double getHoleDensity();
	double geteEmissvity();

	double getM();
	double getDensity();
	double getValue_Height();

	double getValue_JingYeZhu();
	double getValue_MoCaZuLi();

	void setValue_Height(double height);
	void setM(double m);

	void PrintArgClass();

private:
	/*
	�������
	*/
	double pressureJ = 0; //����ѹ��(���Ƶ�λ Mpa Ӣ�Ƶ�λpsi)
	double q = 0; //����
	double sandMass = 0; //��ǰɰ����(���Ƶ�λkg  Ӣ�Ƶ�λlb)
	double dVolume = 0;  //�˶�Һ�����
	int kind = 0; //��ǰ��Һ�����ʹ�Һ������1(��λ��)��ɰҺ����2(��λ��)
	double dVorD = 0; //��Һ�������ܶ� (���Ƶ�λkg/m^3 Ӣ�Ƶ�λ��ppg)
					  //��ɰҺ����֧�ż�����ܶ�(���Ƶ�λkg/m^3 Ӣ�Ƶ�λ ppg)
	double dTorT = 0; //��Һ������Һ��ճ��(��λmpa.s)����.��
					  // ��ɰҺ����֧�ż����ܶ�(���Ƶ�λkg/m^3 Ӣ�Ƶ�λppg)
	double resistanceBend = 0; //����Ħ��(���Ƶ�λ Mpa Ӣ�Ƶ�λpsi)
	double speedFlow = 0; //����ϵ��(��λ��)������Һ�����Ͳ�ͬ������ϵ����ͬ
	double slope = 0; //б���λm������ʦģ����Ҫ�仯��б�
	double sandRatio = 0; //ɰ��
	double dragReduction = 0; //������
	double holeLength = 0;//��׶γ���(��λm)
	double holeDensity = 0;//�����ܶȣ���λ�ף�m��
	double emissvity = 0;//������
	/*
	���ݲ���������м��������
	*/
	double M = 0; //֧�ż�����������ݴ��μ���õ���
	double density = 0; //֧�ּ��ܶȣ���kindֵ�й�
	double value_Height = 0; //ÿһ�θ߶ȡ�
	/*
	��Ҫ���������
	*/
	double value_JingYeZhu = 0; //��Ͳ��Һ��ѹ��
	double value_MoCaZuLi = 0; //��ͲĦ������

};
