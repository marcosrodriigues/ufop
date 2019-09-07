import { Injectable } from '@angular/core';
import { HttpClient } from '@angular/common/http';

@Injectable({
  providedIn: 'root'
})
export class RepublicaService {

  constructor(private _http: HttpClient) { }

  private baseUrl: string = "http://localhost:8080/republica";

  findAll() {
    return this._http.get(this.baseUrl);
  }

  findByUf(uf) {
    return this._http.get(this.baseUrl + "/byUf/" + uf);
  }

  findByUfAndCity(uf, city) {
    return this._http.get(this.baseUrl + "/" + uf + "/" + city);
  }
  
}
