SELECT 
    p.product_id,
    IFNULL(
        ROUND(
            SUM(
                CASE 
                    WHEN u.purchase_date BETWEEN p.start_date AND p.end_date 
                    THEN p.price * u.units 
                    ELSE 0 
                END
            ) / 
            NULLIF(
                SUM(
                    CASE 
                        WHEN u.purchase_date BETWEEN p.start_date AND p.end_date 
                        THEN u.units 
                        ELSE 0 
                    END
                ), 0
            ), 
        2), 
    0) AS average_price
FROM 
    Prices p
LEFT JOIN 
    UnitsSold u 
ON 
    p.product_id = u.product_id
GROUP BY 
    p.product_id;
