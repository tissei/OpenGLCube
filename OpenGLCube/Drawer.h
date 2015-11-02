class Drawer {
public:
	void Start(unsigned int mode);
	void SetColor(double c, double m, double y);
	void AddCoordinate(double x, double y, double z);
	void End();
};