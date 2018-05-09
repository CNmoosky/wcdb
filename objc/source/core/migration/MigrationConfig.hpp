/*
 * Tencent is pleased to support the open source community by making
 * WCDB available.
 *
 * Copyright (C) 2017 THL A29 Limited, a Tencent company.
 * All rights reserved.
 *
 * Licensed under the BSD 3-Clause License (the "License"); you may not use
 * this file except in compliance with the License. You may obtain a copy of
 * the License at
 *
 *       https://opensource.org/licenses/BSD-3-Clause
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef MigrationConfig_hpp
#define MigrationConfig_hpp

#include <WCDB/Config.hpp>
#include <WCDB/MigrationSetting.hpp>

#pragma GCC visibility push(hidden)

namespace WCDB {

class MigrationConfig : public Config {
public:
    static std::shared_ptr<Config> configWithSetting(MigrationSetting *setting);
    static constexpr const int order = INT_MIN + 4;

    static const std::string &name();

    bool invoke(Handle *handle) const override;

protected:
    MigrationConfig(MigrationSetting *setting);
    MigrationConfig(const MigrationConfig &) = delete;
    MigrationConfig &operator=(const MigrationConfig &) = delete;

    MigrationSetting *m_setting;

    bool doAttachSchema(Handle *handle) const;
    bool doCreateView(Handle *handle, bool &schemaChanged) const;
};

} //namespace WCDB

#pragma GCC visibility pop

#endif /* MigrationConfig_hpp */