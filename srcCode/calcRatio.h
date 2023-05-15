class caclRatio
{
private:
public:
    // Constructor for caclRatio object
    caclRatio(){

    };

    // Public Methods
    double calcRatioPM(double revenue, double expenses)
    {
        return ((revenue - expenses) / revenue);
    };
    double calcRatioRoA(double revenue, double expenses, double assets)
    {
        return ((revenue - expenses) / assets);
    };
    double calcRatioDE(double assets, double liabilities)
    {
        return (assets / liabilities);
    };

    // Destructor for caclRatio object
    ~caclRatio(){};
};