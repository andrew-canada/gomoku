package com.andrew.shopping;

import javax.annotation.Nonnull;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import com.andrew.shopping.bo.BusinessCustomer;
import com.andrew.shopping.bo.CreditCard;
import com.andrew.shopping.bo.Customer;
import com.andrew.shopping.bo.NonprofitCustomer;
import com.andrew.shopping.bo.Product;
import com.andrew.shopping.bo.ShoppingCart;

@Nonnull
public class App {
	private static final Logger LOGGER = LoggerFactory.getLogger(App.class);

	public static void main(String[] args) {
		CreditCard visa = new CreditCard(123);

		Product apple = new Product("apple", 1.1);
		Product computer = new Product("computer", 111.5);

		ShoppingCart andrewCart = new ShoppingCart();

		Customer andrew = new BusinessCustomer("andrew", visa);
		Customer andrew1 = new BusinessCustomer("andrew", visa);

		andrew.setShoppingCart(andrewCart);
		andrew.addProduct(computer);
		andrew.addProduct(apple);

		Customer andre = new NonprofitCustomer("andre", visa);

		LOGGER.debug("total cost: {}", andrewCart.getTotalCost());
		LOGGER.debug("customer info: {}", andrew);

		LOGGER.debug("discount: {}", andrew.calculateDiscount());
		LOGGER.debug("discount: {}", andre.calculateDiscount());

	}
}
