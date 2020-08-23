#ifndef APG_SHOPNDROP__OBJECT_INITIALIZER_H
#define APG_SHOPNDROP__OBJECT_INITIALIZER_H

// includes
#include "protocol.h"

namespace shopndrop_protocol
{

// objects

void initialize( ProductItem * res
    , const std::string &  name
    , const std::string &  unit
    , double price
    , double weight
 );
void initialize( ShoppingItem * res
    , uint32_t product_item_id
    , uint32_t amount
 );
void initialize( ShoppingList * res
    , const std::vector<ShoppingItem> &  items
 );
void initialize( GeoPosition * res
    , uint32_t plz
    , double latitude
    , double longitude
 );
void initialize( RideSummary * res
    , const GeoPosition &  position
    , const basic_objects::LocalTime &  delivery_time
    , double max_weight
 );
void initialize( Ride * res
    , bool is_open
    , const RideSummary &  summary
    , const std::vector<uint32_t> &  pending_order_ids
    , uint32_t accepted_order_id
    , ride_resolution_e resolution
 );
void initialize( Address * res
    , uint32_t plz
    , const std::string &  country
    , const std::string &  city
    , const std::string &  street
    , const std::string &  house_number
    , const std::string &  extra_address_line
 );
void initialize( Order * res
    , bool is_open
    , uint32_t ride_id
    , const Address &  delivery_address
    , uint32_t shopping_list_id
    , order_state_e state
    , order_resolution_e resolution
 );

// base messages

void initialize( Request * res
    , const std::string &  base_class_param_1
 );

// messages

void initialize( AddRideRequest * res
    , const std::string &  base_class_param_1
    , const RideSummary &  ride
 );
void initialize( AddRideResponse * res
    , uint32_t ride_id
 );
void initialize( CancelRideRequest * res
    , const std::string &  base_class_param_1
    , uint32_t ride_id
 );
void initialize( CancelRideResponse * res
 );
void initialize( GetRideRequest * res
    , const std::string &  base_class_param_1
    , uint32_t ride_id
 );
void initialize( GetRideResponse * res
    , const Ride &  ride
 );
void initialize( AddOrderRequest * res
    , const std::string &  base_class_param_1
    , uint32_t ride_id
    , const ShoppingList &  shopping_list
    , const Address &  delivery_address
 );
void initialize( AddOrderResponse * res
    , uint32_t order_id
 );
void initialize( CancelOrderRequest * res
    , const std::string &  base_class_param_1
    , uint32_t order_id
 );
void initialize( CancelOrderResponse * res
 );
void initialize( AcceptOrderRequest * res
    , const std::string &  base_class_param_1
    , uint32_t order_id
 );
void initialize( AcceptOrderResponse * res
 );
void initialize( DeclineOrderRequest * res
    , const std::string &  base_class_param_1
    , uint32_t order_id
 );
void initialize( DeclineOrderResponse * res
 );
void initialize( MarkDeliveredOrderRequest * res
    , const std::string &  base_class_param_1
    , uint32_t order_id
 );
void initialize( MarkDeliveredOrderResponse * res
 );
void initialize( RateShopperRequest * res
    , const std::string &  base_class_param_1
    , uint32_t order_id
    , uint32_t stars
 );
void initialize( RateShopperResponse * res
 );

// messages (constructors)

AddRideRequest * create_AddRideRequest(
    const std::string &  base_class_param_1
    , const RideSummary &  ride
 );
AddRideResponse * create_AddRideResponse(
    uint32_t ride_id
 );
CancelRideRequest * create_CancelRideRequest(
    const std::string &  base_class_param_1
    , uint32_t ride_id
 );
CancelRideResponse * create_CancelRideResponse(
 );
GetRideRequest * create_GetRideRequest(
    const std::string &  base_class_param_1
    , uint32_t ride_id
 );
GetRideResponse * create_GetRideResponse(
    const Ride &  ride
 );
AddOrderRequest * create_AddOrderRequest(
    const std::string &  base_class_param_1
    , uint32_t ride_id
    , const ShoppingList &  shopping_list
    , const Address &  delivery_address
 );
AddOrderResponse * create_AddOrderResponse(
    uint32_t order_id
 );
CancelOrderRequest * create_CancelOrderRequest(
    const std::string &  base_class_param_1
    , uint32_t order_id
 );
CancelOrderResponse * create_CancelOrderResponse(
 );
AcceptOrderRequest * create_AcceptOrderRequest(
    const std::string &  base_class_param_1
    , uint32_t order_id
 );
AcceptOrderResponse * create_AcceptOrderResponse(
 );
DeclineOrderRequest * create_DeclineOrderRequest(
    const std::string &  base_class_param_1
    , uint32_t order_id
 );
DeclineOrderResponse * create_DeclineOrderResponse(
 );
MarkDeliveredOrderRequest * create_MarkDeliveredOrderRequest(
    const std::string &  base_class_param_1
    , uint32_t order_id
 );
MarkDeliveredOrderResponse * create_MarkDeliveredOrderResponse(
 );
RateShopperRequest * create_RateShopperRequest(
    const std::string &  base_class_param_1
    , uint32_t order_id
    , uint32_t stars
 );
RateShopperResponse * create_RateShopperResponse(
 );

} // namespace shopndrop_protocol

#endif // APG_SHOPNDROP__OBJECT_INITIALIZER_H
