#include "dqInfoCollector.h"

namespace dqEngineSDK {
  
  dqInfoCollector::dqInfoCollector()
  {
    this->init();
  }

  dqInfoCollector::~dqInfoCollector()
  {
    this->destroy();
  }

  void dqInfoCollector::init()
  {
    m_tokenList.clear();
  }

  void dqInfoCollector::destroy()
  {
    m_tokenList.clear();
  }

  void dqInfoCollector::addToken(dqInfoToken token)
  {
    m_tokenList.push_back(token);
  }

  void dqInfoCollector::printTokens()
  {

  }
}