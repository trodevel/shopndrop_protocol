#ifndef APG_SHOPNDROP_PROTOCOL__STR_HELPER_H
#define APG_SHOPNDROP_PROTOCOL__STR_HELPER_H

// system includes
#include <sstream>

// includes
#include "protocol.h"

namespace shopndrop_protocol
{

namespace str_helper
{

// enums
std::ostream & write( std::ostream & os, const ride_resolution_e r );
std::ostream & write( std::ostream & os, const order_resolution_e r );
std::ostream & write( std::ostream & os, const order_state_e r );
std::ostream & write( std::ostream & os, const gender_e r );

// objects
std::ostream & write( std::ostream & os, const ProductItem & r );
std::ostream & write( std::ostream & os, const ShoppingItem & r );
std::ostream & write( std::ostream & os, const ShoppingList & r );
std::ostream & write( std::ostream & os, const GeoPosition & r );
std::ostream & write( std::ostream & os, const RideSummary & r );
std::ostream & write( std::ostream & os, const Ride & r );
std::ostream & write( std::ostream & os, const Address & r );
std::ostream & write( std::ostream & os, const Order & r );

// base messages
std::ostream & write( std::ostream & os, const Request & r );

// messages
std::ostream & write( std::ostream & os, const AddRideRequest & r );
std::ostream & write( std::ostream & os, const AddRideResponse & r );
std::ostream & write( std::ostream & os, const CancelRideRequest & r );
std::ostream & write( std::ostream & os, const CancelRideResponse & r );
std::ostream & write( std::ostream & os, const GetRideRequest & r );
std::ostream & write( std::ostream & os, const GetRideResponse & r );
std::ostream & write( std::ostream & os, const AddOrderRequest & r );
std::ostream & write( std::ostream & os, const AddOrderResponse & r );
std::ostream & write( std::ostream & os, const CancelOrderRequest & r );
std::ostream & write( std::ostream & os, const CancelOrderResponse & r );
std::ostream & write( std::ostream & os, const AcceptOrderRequest & r );
std::ostream & write( std::ostream & os, const AcceptOrderResponse & r );
std::ostream & write( std::ostream & os, const DeclineOrderRequest & r );
std::ostream & write( std::ostream & os, const DeclineOrderResponse & r );
std::ostream & write( std::ostream & os, const MarkDeliveredOrderRequest & r );
std::ostream & write( std::ostream & os, const MarkDeliveredOrderResponse & r );
std::ostream & write( std::ostream & os, const RateShopperRequest & r );
std::ostream & write( std::ostream & os, const RateShopperResponse & r );

template<class T>
std::string to_string( const T & l )
{
    std::ostringstream os;

    write( os, l );

    return os.str();
}

} // namespace str_helper

} // namespace shopndrop_protocol

#endif // APG_SHOPNDROP_PROTOCOL__STR_HELPER_H
