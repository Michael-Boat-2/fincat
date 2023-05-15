class caclRatio
{
private:
public:
    caclRatio(){

    };

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
};