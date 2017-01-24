#pragma once
/*
此类用于存储可变参数，同时存入此变量下的井筒静液柱压力、井筒摩擦阻力、净压力,模拟每一段液体。
*/
class ArgClass {
public:
	ArgClass();
	ArgClass(double pressureJ, double q, double sandMass, double dVolume, int kind, double dVorD,
		double dTorT, double resistanceBend, double speedFlow, double slope,
		double sandRatio, double dragReduction, double holeLength, double holeDensity, double emissvity);
	//15个变量。
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
	传入参数
	*/
	double pressureJ = 0; //井口压力(公制单位 Mpa 英制单位psi)
	double q = 0; //排量
	double sandMass = 0; //当前砂质量(公制单位kg  英制单位lb)
	double dVolume = 0;  //此段液体体积
	int kind = 0; //当前加液的类型纯液体输入1(单位无)混砂液输入2(单位无)
	double dVorD = 0; //纯液体输入密度 (公制单位kg/m^3 英制单位磅ppg)
					  //混砂液输入支撑剂体积密度(公制单位kg/m^3 英制单位 ppg)
	double dTorT = 0; //纯液体输入液体粘度(单位mpa.s)毫帕.秒
					  // 混砂液输入支撑剂视密度(公制单位kg/m^3 英制单位ppg)
	double resistanceBend = 0; //弯曲摩阻(公制单位 Mpa 英制单位psi)
	double speedFlow = 0; //流速系数(单位无)：根据液体类型不同，流速系数不同
	double slope = 0; //斜深，单位m（胡老师模型需要变化的斜深）
	double sandRatio = 0; //砂比
	double dragReduction = 0; //减阻率
	double holeLength = 0;//射孔段长度(单位m)
	double holeDensity = 0;//孔眼密度（单位孔／m）
	double emissvity = 0;//发射率
	/*
	根据参数计算的中间计算量。
	*/
	double M = 0; //支撑剂质量，需根据传参计算得到。
	double density = 0; //支持剂密度，与kind值有关
	double value_Height = 0; //每一段高度。
	/*
	重要结果计算量
	*/
	double value_JingYeZhu = 0; //井筒静液柱压力
	double value_MoCaZuLi = 0; //井筒摩擦阻力

};
