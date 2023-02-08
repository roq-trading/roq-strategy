/* Copyright (c) 2017-2023, Hans Erik Thrane */

#pragma once

#include <memory>

#include "roq/client.hpp"

#include "roq/cache/market_by_order.hpp"

namespace simple {

struct Strategy final : public roq::client::Handler {
  explicit Strategy(roq::client::Dispatcher &);

  Strategy(Strategy &&) = default;
  Strategy(Strategy const &) = delete;

 protected:
  void operator()(roq::Event<roq::Timer> const &) override;
  void operator()(roq::Event<roq::Connected> const &) override;
  void operator()(roq::Event<roq::Disconnected> const &) override;
  void operator()(roq::Event<roq::DownloadBegin> const &) override;
  void operator()(roq::Event<roq::DownloadEnd> const &) override;
  void operator()(roq::Event<roq::GatewayStatus> const &) override;
  void operator()(roq::Event<roq::ReferenceData> const &) override;
  void operator()(roq::Event<roq::MarketStatus> const &) override;
  void operator()(roq::Event<roq::MarketByPriceUpdate> const &) override;
  void operator()(roq::Event<roq::MarketByOrderUpdate> const &) override;
  void operator()(roq::Event<roq::OrderAck> const &) override;
  void operator()(roq::Event<roq::OrderUpdate> const &) override;
  void operator()(roq::Event<roq::TradeUpdate> const &) override;
  void operator()(roq::Event<roq::PositionUpdate> const &) override;
  void operator()(roq::Event<roq::FundsUpdate> const &) override;

 private:
  roq::client::Dispatcher &dispatcher_;
  std::unique_ptr<roq::cache::MarketByOrder> market_by_order_;
};

}  // namespace simple
