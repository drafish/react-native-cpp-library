#pragma once

namespace example {

  class Test {
  private:
    friend class TestBinding;

    int runTest() const;
  };

}
