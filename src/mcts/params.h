/*
  This file is part of Leela Chess Zero.
  Copyright (C) 2018 The LCZero Authors

  Leela Chess is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Leela Chess is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Leela Chess.  If not, see <http://www.gnu.org/licenses/>.

  Additional permission under GNU GPL version 3 section 7

  If you modify this Program, or any covered work, by linking or
  combining it with NVIDIA Corporation's libraries from the NVIDIA CUDA
  Toolkit and the NVIDIA CUDA Deep Neural Network library (or a
  modified version of those libraries), containing parts covered by the
  terms of the respective license agreement, the licensors of this
  Program grant you additional permission to convey the resulting work.
*/

#pragma once

#include "neural/encoder.h"
#include "utils/optionsdict.h"
#include "utils/optionsparser.h"

namespace lczero {

class SearchParams {
 public:
  SearchParams(const OptionsDict& options);
  SearchParams(const SearchParams&) = delete;

  // Populates UciOptions with search parameters.
  static void Populate(OptionsParser* options);

  // Parameter getters.
  int GetMiniBatchSize() const {
    return options_.Get<int>(kMiniBatchSizeId.GetId());
  }
  int GetMaxPrefetchBatch() const {
    return options_.Get<int>(kMaxPrefetchBatchId.GetId());
  }
  float GetCpuct() const { return kCpuct; }
  float GetTradePenalty() const { return kTradePenalty; }
  float GetTradePenalty2() const { return kTradePenalty2; }
  float GetTemperature() const {
    return options_.Get<float>(kTemperatureId.GetId());
  }
  float GetTemperatureVisitOffset() const {
    return options_.Get<float>(kTemperatureVisitOffsetId.GetId());
  }
  int GetTempDecayMoves() const {
    return options_.Get<int>(kTempDecayMovesId.GetId());
  }
  bool GetNoise() const { return kNoise; }
  bool GetVerboseStats() const {
    return options_.Get<bool>(kVerboseStatsId.GetId());
  }
  float GetSmartPruningFactor() const { return kSmartPruningFactor; }
  float GetFpuReduction() const { return kFpuReduction; }
  int GetCacheHistoryLength() const { return kCacheHistoryLength; }
  float GetPolicySoftmaxTemp() const { return kPolicySoftmaxTemp; }
  int GetMaxCollisionEvents() const { return kMaxCollisionEvents; }
  int GetMaxCollisionVisitsId() const { return kMaxCollisionVisits; }
  bool GetOutOfOrderEval() const { return kOutOfOrderEval; }
  int GetMultiPv() const { return options_.Get<int>(kMultiPvId.GetId()); }
  std::string GetScoreType() const {
    return options_.Get<std::string>(kScoreTypeId.GetId());
  }
  FillEmptyHistory GetHistoryFill() const { return kHistoryFill; }

  // Search parameter IDs.
  static const OptionId kMiniBatchSizeId;
  static const OptionId kMaxPrefetchBatchId;
  static const OptionId kCpuctId;
  static const OptionId kTradePenaltyId;
  static const OptionId kTradePenalty2Id;
  static const OptionId kTemperatureId;
  static const OptionId kTempDecayMovesId;
  static const OptionId kTemperatureVisitOffsetId;
  static const OptionId kNoiseId;
  static const OptionId kVerboseStatsId;
  static const OptionId kSmartPruningFactorId;
  static const OptionId kFpuReductionId;
  static const OptionId kCacheHistoryLengthId;
  static const OptionId kPolicySoftmaxTempId;
  static const OptionId kMaxCollisionEventsId;
  static const OptionId kMaxCollisionVisitsId;
  static const OptionId kOutOfOrderEvalId;
  static const OptionId kMultiPvId;
  static const OptionId kScoreTypeId;
  static const OptionId kHistoryFillId;

 private:
  const OptionsDict& options_;
  // Cached parameter values. Values have to be cached if either:
  // 1. Parameter is accessed often and has to be cached for performance
  // reasons.
  // 2. Parameter has to stay the say during the search.
  // TODO(crem) Some of those parameters can be converted to be dynamic after
  //            trivial search optimiations.
  const float kCpuct;
  const float kTradePenalty;
  const float kTradePenalty2;
  const bool kNoise;
  const float kSmartPruningFactor;
  const float kFpuReduction;
  const int kCacheHistoryLength;
  const float kPolicySoftmaxTemp;
  const int kMaxCollisionEvents;
  const int kMaxCollisionVisits;
  const bool kOutOfOrderEval;
  const FillEmptyHistory kHistoryFill;
};

}  // namespace lczero
