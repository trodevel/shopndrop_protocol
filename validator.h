#ifndef APG_SHOPNDROP__VALIDATOR_H
#define APG_SHOPNDROP__VALIDATOR_H

// includes
#include "protocol.h"

namespace shopndrop_protocol
{

namespace validator
{

// enums
bool validate( const std::string & prefix, const ride_resolution_e r );
bool validate( const std::string & prefix, const order_resolution_e r );
bool validate( const std::string & prefix, const order_state_e r );
bool validate( const std::string & prefix, const gender_e r );

// objects
bool validate( const std::string & prefix, const ProductItem & r );
bool validate( const std::string & prefix, const ShoppingItem & r );
bool validate( const std::string & prefix, const ShoppingList & r );
bool validate( const std::string & prefix, const GeoPosition & r );
bool validate( const std::string & prefix, const RideSummary & r );
bool validate( const std::string & prefix, const Ride & r );
bool validate( const std::string & prefix, const Address & r );
bool validate( const std::string & prefix, const Order & r );

// base messages
bool validate( const Request & r );

// messages
bool validate( const AddRideRequest & r );
bool validate( const AddRideResponse & r );
bool validate( const CancelRideRequest & r );
bool validate( const CancelRideResponse & r );
bool validate( const GetRideRequest & r );
bool validate( const GetRideResponse & r );
bool validate( const AddOrderRequest & r );
bool validate( const AddOrderResponse & r );
bool validate( const CancelOrderRequest & r );
bool validate( const CancelOrderResponse & r );
bool validate( const AcceptOrderRequest & r );
bool validate( const AcceptOrderResponse & r );
bool validate( const DeclineOrderRequest & r );
bool validate( const DeclineOrderResponse & r );
bool validate( const MarkDeliveredOrderRequest & r );
bool validate( const MarkDeliveredOrderResponse & r );
bool validate( const RateShopperRequest & r );
bool validate( const RateShopperResponse & r );

} // namespace validator

} // namespace shopndrop_protocol

#endif // APG_SHOPNDROP__VALIDATOR_H
