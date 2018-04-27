#pragma once
#include "dqGraphicsDXPrerequisites.h"

namespace dqEngineSDK
{

  namespace INFORMATION_TYPE {
    enum E {
      kUndefined,
      kInfo,
      kWarning,
      kError,
      kCritical
    };
  }

  struct dqInfoToken {
    uint32  line;
    String  fileName;
    String  description;
    INFORMATION_TYPE::E type;
  };

  class DQ_GRAPHICSDX_EXPORT dqInfoCollector
  {
  public:
    dqInfoCollector();
    ~dqInfoCollector();

    void init();

    void destroy();

    void addToken(dqInfoToken token);

    void printTokens();

  private:
    Vector <dqInfoToken> m_tokenList;
  };
}
