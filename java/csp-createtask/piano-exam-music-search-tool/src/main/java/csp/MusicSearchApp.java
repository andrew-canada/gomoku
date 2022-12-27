package csp;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

/**
 * Piano Exam Music Search Tool: quickly find an appropriate piano piece to
 * learn based on its level, speed, and/or character
 */
public class MusicSearchApp {

	// @formatter:off
	private static final String TABLE_HEADING = String.format("%-7s %-15s %-10s %-35s %-15s %-3s\n", 
			"Level", "Speed", "Character", "Title", "Composer", "Period");
	// @formatter:on

	public static void main(String[] args) throws IOException {
		MusicSearchApp musicSearchApp = new MusicSearchApp();
		List<PianoPiece> pianoPieceList = musicSearchApp.createPianoPieceList();

		try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
			System.out.println("Welcome to Piano Exam Music Search Tool! \nOptions to Enter:");
			musicSearchApp.showMainMenu();
			String action = br.readLine();
			while (!action.equalsIgnoreCase("q")) {
				if (action.equalsIgnoreCase("s")) {
					SearchOptions searchOptions = musicSearchApp.captureSearchOptions(br);
					List<PianoPiece> searchResultList = musicSearchApp.searchMusic(searchOptions, pianoPieceList);
					musicSearchApp.printSearchResult(searchResultList);
				} else {
					System.out.println("Invalid choice. Try again.");
				}
				musicSearchApp.showMainMenu();
				action = br.readLine();
			}
			System.out.println("Thank you for using the Piano Exam Music Search Tool!");
		} catch (IOException ioe) {
			System.out.println("error");
		}
	}

	/**
	 * Generate a list of PianoPiece objects from a CSV file with all piano pieces
	 * 
	 * @return pianoPieceList, a list of all PianoPiece
	 */
	private List<PianoPiece> createPianoPieceList() {
		List<PianoPiece> pianoPieceList = new ArrayList<>();
		InputStreamReader musicListReader = new InputStreamReader(
				getClass().getClassLoader().getResourceAsStream("music-list.csv"));
		try (BufferedReader br = new BufferedReader(musicListReader)) {
			for (String line = br.readLine(); line != null; line = br.readLine()) {
				String[] pieceCharacteristics = line.split("\\|");
				PianoPiece pp = new PianoPiece(pieceCharacteristics[0], pieceCharacteristics[2],
						pieceCharacteristics[5], pieceCharacteristics[6], pieceCharacteristics[9],
						pieceCharacteristics[8]);
				pianoPieceList.add(pp);
			}
		} catch (IOException ioe) {
			System.out.printf("IOException occurred. Error message: %s", ioe.getMessage());
		}
		return pianoPieceList;
	}

	/**
	 * Print the main menu. 2 options: search and quit
	 */
	private void showMainMenu() {
		System.out.println("\"s\" -> Search");
		System.out.println("\"q\" -> Quit");
	}

	/**
	 * Create a SearchOptions object (storing music search criteria) from user input
	 * 
	 * @param br, a BufferedReader
	 * @return searchOptions, a SearchOptions object
	 */
	private SearchOptions captureSearchOptions(BufferedReader br) throws IOException {
		SearchOptions searchOptions = new SearchOptions();
		searchOptions.setAllOptionsUsed(true);
		System.out.println("Press the \"Enter\" key to skip a criterion:");
		System.out.println("What piece level (5-10) would you like to try? (this field is required)");
		String level = br.readLine();

		// validate input to ensure that the level field is never empty
		while (level.equals("")) {
			System.out.println("Please enter a piece level. (this field is required)");
			level = br.readLine();
		}
		searchOptions.setLevel(level);

		System.out.println("What piece speed would you like? (slow, medium, fast, extremely fast)");
		searchOptions.setSpeed(br.readLine());
		if (searchOptions.getSpeed().equals("")) {
			searchOptions.setAllOptionsUsed(false);
		}

		System.out.println("What music character would you like to try? (sad, frantic, happy, peaceful, majestic)");
		searchOptions.setMusicCharacter(br.readLine());
		if (searchOptions.getMusicCharacter().equals("")) {
			searchOptions.setAllOptionsUsed(false);
		}

		System.out.println(
				"How many results (if applicable) would you like to display? (Press the \"Enter\" key for all)");
		String numResults = br.readLine();
		if (numResults.equals("")) {
			// set to infinity to represent that the field was not given
			// used as a flag when searching for pieces in searchMusic method
			searchOptions.setNumResults(Integer.MAX_VALUE);
		} else {
			searchOptions.setNumResults(Integer.parseInt(numResults));
		}
		return searchOptions;
	}

	/**
	 * Find all PianoPiece that fulfill a search criteria. Return them in a list.
	 * 
	 * @param searchOptions, a SearchOptions object; pianoPieceList, a list of all
	 *                       PianoPiece
	 * @return searchResultList, a list of PianoPiece that fulfill the criteria
	 */
	private List<PianoPiece> searchMusic(SearchOptions searchOptions, List<PianoPiece> pianoPieceList) {

		List<PianoPiece> searchResultList = new ArrayList<>();

		for (PianoPiece pianoPiece : pianoPieceList) {
			if (searchOptions.getNumResults() != searchResultList.size()) {
				// level is never empty, due to input validation in captureSearchOptions method
				// only need to check level once instead of checking inside each if
				if (pianoPiece.getLevel().equalsIgnoreCase(searchOptions.getLevel())) {
					if (searchOptions.getMusicCharacter().equals("") && searchOptions.getSpeed().equals("")) {
						// user only entered level
						searchResultList.add(pianoPiece);
					} else if (searchOptions.isAllOptionsUsed()
							&& pianoPiece.getMusicCharacter().equalsIgnoreCase(searchOptions.getMusicCharacter())
							&& pianoPiece.getSpeed().equalsIgnoreCase(searchOptions.getSpeed())) {
						// user entered level, musicCharacter, and speed
						searchResultList.add(pianoPiece);
					} else if (!searchOptions.isAllOptionsUsed()
							&& (pianoPiece.getMusicCharacter().equalsIgnoreCase(searchOptions.getMusicCharacter())
									|| pianoPiece.getSpeed().equalsIgnoreCase(searchOptions.getSpeed()))) {
						// user entered level and either musicCharacter or speed
						searchResultList.add(pianoPiece);
					}
				}
			} else {
				break; // stop looping because all pieces were found
			}
		}
		return searchResultList;
	}

	/**
	 * Print the list of PianoPiece that result from the music search
	 * 
	 * @param searchResult, a list of PianoPiece
	 */
	private void printSearchResult(List<PianoPiece> searchResult) {
		if (!searchResult.isEmpty()) {
			System.out.println("\nPieces that fit your search criteria:\n");
			System.out.println(TABLE_HEADING);
			searchResult.stream().forEach(System.out::println);
		} else {
			System.out.println("There are no pieces that fit your search criteria.");
		}
		System.out.println();
	}

}
