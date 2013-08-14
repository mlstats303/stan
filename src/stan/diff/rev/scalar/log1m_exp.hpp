#ifndef __STAN__DIFF__REV__LOG1M_EXP_HPP__
#define __STAN__DIFF__REV__LOG1M_EXP_HPP__

#include <stan/diff/rev/var.hpp>
#include <stan/diff/rev/scalar/op/v_vari.hpp>
#include <stan/math/scalar/log1m_exp.hpp>
#include <stan/diff/rev/calculate_chain.hpp>
#include <boost/math/special_functions/expm1.hpp>

namespace stan {
  namespace diff {

    namespace {
      class log1m_exp_v_vari : public op_v_vari {
      public:
        log1m_exp_v_vari(vari* avi) :
          op_v_vari(stan::math::log1m_exp(avi->val_),
                    avi) {
        }
        void chain() {
          //derivative of log(1-exp(x)) = -exp(x)/(1-exp(x)) = -1/(exp(-x)-1) = -1/expm1(-x)
          avi_->adj_ -= adj_ / boost::math::expm1(-(avi_->val_));
        }
      };      
    }

    /**
     * Return the log of 1 minus the exponential of the specified
     * variable.
     */
    inline var log1m_exp(const stan::diff::var& a) {
      return var(new log1m_exp_v_vari(a.vi_));
    }

  }
}
#endif