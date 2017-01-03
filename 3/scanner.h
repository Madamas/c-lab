typedef struct {
	char manufacturer[127];// виготовлювач
	int year;	 // рік виготовлення
	char model[128];// найменування моделі
	float price;// ціна
	int x_size;// горизонтальний розмір області сканування
	int y_size;// вертикальний розмір області сканування
	int optr; // оптичний роподіл
} SCAN_INFO;

