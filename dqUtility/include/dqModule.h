#pragma once

/*

namespace dqEngineSDK
{
  template < class T >
  class dqModule
  {
  public:
  
    static T&
    instance() {
      if (!isStartedUp()) {
        //Error
      }

      if (isDestroyed()) {
        //Error
      }

      return *_instance();
    }

  
    static T*
    instancePtr() {
      if (!isStartedUp()) {
        //Error
      }

      if (isDestroyed()) {
        //Error
      }

      return _instance();
    }

  
    template<class... Args>
    static void
      startUp(Args&& ...args) {
      if (isStartedUp()) {
        //Error
      }

      _instance() = new T(std::forward<Args>(args)...);
      isStartedUp() = true;

      static_cast<Module*>(_instance())->onStartUp();
    }

   
    template<class SubType, class... Args>
    static void
      startUp(Args&& ...args) {
      static_assert(std::is_base_of<T, SubType>::value,
        "Provided type isn't derived from type the Module is initialized with.");

      if (isStartedUp()) {
        //Error
      }

      _instance() = new SubType(std::forward<Args>(args)...);
      isStartedUp() = true;

      static_cast<Module*>(_instance())->onStartUp();
    }

   
    static void
    shutDown() {
      if (isDestroyed()) {
        //Error
      }

      if (!isStartedUp()) {
        //Error
      }

      static_cast<Module*>(_instance())->onShutDown();

      delete(_instance());
      isDestroyed() = true;
    }
      
    static bool
    isStarted() {
      return isStartedUp() && !isDestroyed();
    }

  protected:
    Module() = default;

    virtual
    ~Module() = default;

    Module(Module&&) = delete;

    Module(const Module&) = delete;

    Module&
    operator=(Module&&) = delete;

    Module&
    operator=(const Module&) = delete;

    virtual void
    onStartUp() {}
        
    virtual void
    onShutDown() {}
        
    static T*&
    _instance() {
      static T* inst = nullptr;
      return inst;
    }
        
    static bool&
    isDestroyed() {
      static bool inst = false;
      return inst;
    }
        
    static bool&
    isStartedUp() {
      static bool inst = false;
      return inst;
    }
  };
}

*/