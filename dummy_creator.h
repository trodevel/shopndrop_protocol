#ifndef APG_SHOPNDROP__DUMMY_CREATOR_H
#define APG_SHOPNDROP__DUMMY_CREATOR_H

// includes
#include "protocol.h"

namespace shopndrop_protocol
{

namespace dummy
{

// enums

ride_resolution_e create__ride_resolution_e();
order_resolution_e create__order_resolution_e();
order_state_e create__order_state_e();
gender_e create__gender_e();

// objects

ProductItem create__ProductItem();
ShoppingItem create__ShoppingItem();
ShoppingList create__ShoppingList();
GeoPosition create__GeoPosition();
RideSummary create__RideSummary();
Ride create__Ride();
Address create__Address();
Order create__Order();

// messages

AddRideRequest * create__AddRideRequest();
AddRideResponse * create__AddRideResponse();
CancelRideRequest * create__CancelRideRequest();
CancelRideResponse * create__CancelRideResponse();
GetRideRequest * create__GetRideRequest();
GetRideResponse * create__GetRideResponse();
AddOrderRequest * create__AddOrderRequest();
AddOrderResponse * create__AddOrderResponse();
CancelOrderRequest * create__CancelOrderRequest();
CancelOrderResponse * create__CancelOrderResponse();
AcceptOrderRequest * create__AcceptOrderRequest();
AcceptOrderResponse * create__AcceptOrderResponse();
DeclineOrderRequest * create__DeclineOrderRequest();
DeclineOrderResponse * create__DeclineOrderResponse();
MarkDeliveredOrderRequest * create__MarkDeliveredOrderRequest();
MarkDeliveredOrderResponse * create__MarkDeliveredOrderResponse();
RateShopperRequest * create__RateShopperRequest();
RateShopperResponse * create__RateShopperResponse();

} // namespace dummy

} // namespace shopndrop_protocol

#endif // APG_SHOPNDROP__DUMMY_CREATOR_H
