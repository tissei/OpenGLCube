static class Rotator {
public:
	static double rotateY;
	static double rotateX;
	static double rotateMY;
	static double rotateMX;
	static void CalculateKeyboardRotation(int key, int x, int y);
	static void CalculateMouseRotation(int x, int y);
	static void Rotate();
};