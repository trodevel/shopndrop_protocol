#ifndef APG_SHOPNDROP__ENUMS_H
#define APG_SHOPNDROP__ENUMS_H

namespace shopndrop_protocol
{

enum class request_type_e
{
    UNDEF,
    AddRideRequest,
    AddRideResponse,
    CancelRideRequest,
    CancelRideResponse,
    GetRideRequest,
    GetRideResponse,
    AddOrderRequest,
    AddOrderResponse,
    CancelOrderRequest,
    CancelOrderResponse,
    AcceptOrderRequest,
    AcceptOrderResponse,
    DeclineOrderRequest,
    DeclineOrderResponse,
    MarkDeliveredOrderRequest,
    MarkDeliveredOrderResponse,
    RateShopperRequest,
    RateShopperResponse,
};

} // namespace shopndrop_protocol

#endif // APG_SHOPNDROP__ENUMS_H
