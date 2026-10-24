/*
================================================================================
PROBLEM 05: Online Food Delivery Bill (Multilevel & Initialization Lists)
--------------------------------------------------------------------------------
OBJECTIVE:
Demonstrate Multilevel Inheritance where each level uses Constructor
Initialization Lists to delegate data to its parent class, and computes
values layer-by-layer.

HIERARCHY:
RestaurantOrder (Base) ---> DeliveryService ---> FinalInvoice (Most Derived)

REQUIREMENTS:
1. Base Class: 'RestaurantOrder'
   - Protected Data Members:
     - const int orderId;
     - float itemTotal; // Cost of food items in rupees
   - Public Methods:
     - RestaurantOrder(int id, float foodCost)
       // MUST initialize orderId and itemTotal using an initialization list!

2. Intermediate Class: 'DeliveryService' (publicly inherits RestaurantOrder)
   - Protected Data Members:
     - float deliveryFee;
     - float tip;
   - Public Methods:
     - DeliveryService(int id, float foodCost, float delFee, float riderTip)
       // MUST pass id and foodCost to RestaurantOrder via initialization list,
       // and initialize deliveryFee and tip using the list.
     - float getSubtotal() const;
       // Returns: itemTotal + deliveryFee + tip

3. Most Derived Class: 'FinalInvoice' (publicly inherits DeliveryService)
   - Private Data Members:
     - float gstRate;      // e.g., 0.05 for 5% GST
     - float discountAmount; // e.g., 50.0 rupees coupon
   - Public Methods:
     - FinalInvoice(int id, float foodCost, float delFee, float riderTip,
                    float taxRate, float discount)
       // MUST pass id, foodCost, delFee, riderTip to DeliveryService via
       // initialization list, and initialize gstRate and discountAmount.
     - float calculateFinalPayable();
       // Formula: subtotal = getSubtotal();
       //          tax = subtotal * gstRate;
       //          total = (subtotal + tax) - discountAmount;
       // Returns total.
     - void printDetailedBill();
       // Prints clean itemized bill showing:
       // Order ID, Food Items Total, Delivery Fee, Tip, GST Amount, Discount,
       // and the Final Amount to Pay.

4. In main():
   - Create an invoice:
     FinalInvoice myOrder(8492, 500.0f, 40.0f, 20.0f, 0.05f, 50.0f);
     (Order #8492, Food: Rs 500, Delivery: Rs 40, Tip: Rs 20, GST: 5%, Discount: Rs 50)
   - Call myOrder.printDetailedBill();
================================================================================
*/

#include <iostream>
#include <iomanip>
using namespace std;

class RestaurantOrder
{
protected:
    const int orderId;
    float itemTotal;

public:
    RestaurantOrder(int id, float foodCost) : orderId(id), itemTotal(foodCost) {}
};

class DeliveryService : public RestaurantOrder
{
protected:
    float deliveryFee;
    float Tip;

public:
    DeliveryService(int id, float foodCost, float delFee, float riderTip) : RestaurantOrder(id, foodCost), deliveryFee(delFee), Tip(riderTip) {}

    const float getSubtotal()
    {
        return itemTotal + deliveryFee + Tip;
    }
};

class FinalInvoice : public DeliveryService
{

    float gstRate;
    float discountAmount;

public:
    FinalInvoice(int id, float foodCost, float delFee, float riderTip,
                 float taxRate, float discount) : DeliveryService(id, foodCost, delFee, riderTip), gstRate(taxRate), discountAmount(discount) {}

    const float payable()
    {
        float subtotal = getSubtotal();

        return (subtotal + (subtotal * gstRate) - discountAmount);
    }

    void printDetailedBill()
    {
        float subtotal = getSubtotal();
        float tax = subtotal * gstRate;
        float finalPayable = payable();

        cout << fixed << setprecision(2);
        cout << "======= SWIGGY / ZOMATO INVOICE =======" << endl;
        cout << "Order ID       : #" << orderId << endl;
        cout << "Food Total     : Rs. " << itemTotal << endl;
        cout << "Delivery Fee   : Rs. " << deliveryFee << endl;
        cout << "Rider Tip      : Rs. " << Tip << endl;
        cout << "---------------------------------------" << endl;
        cout << "Subtotal       : Rs. " << subtotal << endl;
        cout << "GST (5%)       : Rs. " << tax << endl;
        cout << "Coupon Discount: -Rs. " << discountAmount << endl;
        cout << "=======================================" << endl;
        cout << "Final Payable  : Rs. " << finalPayable << endl;
        cout << "=======================================" << endl;
    }
};

int main()
{
    FinalInvoice f(8492, 500.0f, 40.0f, 20.0f, 0.05f, 50.0f);
    f.printDetailedBill();

    return 0;
}
