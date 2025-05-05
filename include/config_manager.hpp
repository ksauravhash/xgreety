#pragma once

#define CONFIG_PATH "/etc/xgreety/xgreety.conf"

namespace xgreety {

class ConfigManager {
 private:
 public:
  void loadConfig();
};

}  // namespace xgreety