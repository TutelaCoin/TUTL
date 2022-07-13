// Copyright (c) 2020 The Tutela developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
 
#include <amount.h>
#include <util.h>

/**
 * The number of blocks that both new and old MN collateral value will
 * be accepted, for smoother transition.
 */
const unsigned int COLLATERAL_TRANSITION_BLOCKS = 100;

/**
 * Determine the masternode collateral value based on block height
 */
CAmount CollateralRequired(int nHeight)
{
    if (nHeight > 1500000) return    50000 * COIN;
    if (nHeight > 1400000) return    45000 * COIN;
    if (nHeight > 1300000) return    40000 * COIN;
    if (nHeight > 1200000) return    35000 * COIN;
    if (nHeight > 1100000) return    30000 * COIN;
    if (nHeight > 1000000) return    25000 * COIN;
    if (nHeight >  900000) return    10000 * COIN;
    if (nHeight >  800000) return     9000 * COIN;
    if (nHeight >  700000) return     8000 * COIN;
    if (nHeight >  600000) return     7000 * COIN;
    if (nHeight >  500000) return     6000 * COIN;
    if (nHeight >  400000) return     5000 * COIN;
    if (nHeight >  300000) return     4000 * COIN;
    if (nHeight >  200000) return     3000 * COIN;
    if (nHeight >  100000) return     2000 * COIN;
         
    return 1000 * COIN;
}


/**
 * Provide transition period for masternode collateral change to avoid
 * unneccessary issues to masternode operators for the amount of 
 * COLLATERAL_TRANSITION_BLOCKS blocks during the collateral change.
 */
bool IsValidCollateral(CAmount nAmountToCheck, int nHeight)
{
    return (
        nAmountToCheck == CollateralRequired(nHeight) || 
        nAmountToCheck == CollateralRequired(nHeight - floor(COLLATERAL_TRANSITION_BLOCKS / 2)) ||
        nAmountToCheck == CollateralRequired(nHeight + floor(COLLATERAL_TRANSITION_BLOCKS / 2))
        );
}
